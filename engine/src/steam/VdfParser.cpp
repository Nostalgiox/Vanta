#include "vanta/steam/VdfParser.hpp"

#include <cctype>
#include <stdexcept>
#include <vector>

namespace vanta::steam
{

    const VdfNode *VdfNode::get(const std::string &key) const
    {
        const auto it = children.find(key);

        if (it == children.end())
        {
            return nullptr;
        }

        return &it->second;
    }

    namespace
    {

        std::vector<std::string> tokenize(const std::string &content)
        {
            std::vector<std::string> tokens;

            std::size_t i = 0;

            while (i < content.size())
            {
                const char c = content[i];

                if (std::isspace(static_cast<unsigned char>(c)))
                {
                    ++i;
                    continue;
                }

                // Comments
                if (c == '/' && i + 1 < content.size() && content[i + 1] == '/')
                {
                    while (i < content.size() && content[i] != '\n')
                    {
                        ++i;
                    }
                    continue;
                }

                if (c == '{' || c == '}')
                {
                    tokens.emplace_back(1, c);
                    ++i;
                    continue;
                }

                if (c == '"')
                {
                    ++i;

                    std::string token;
                    bool closed = false;

                    while (i < content.size())
                    {
                        char current = content[i++];

                        if (current == '\\' && i < content.size())
                        {
                            token += content[i++];
                        }
                        else if (current == '"')
                        {
                            closed = true;
                            break;
                        }
                        else
                        {
                            token += current;
                        }
                    }

                    if (!closed)
                    {
                        throw std::runtime_error("Unterminated quoted string in VDF");
                    }

                    tokens.push_back(token);
                    continue;
                }

                // Unquoted token
                std::string token;

                while (i < content.size())
                {
                    const char current = content[i];

                    if (std::isspace(static_cast<unsigned char>(current)) ||
                        current == '{' || current == '}')
                    {
                        break;
                    }

                    token += current;
                    ++i;
                }

                if (token.empty())
                {
                    throw std::runtime_error("Invalid token in VDF");
                }

                tokens.push_back(token);
            }

            return tokens;
        }

        VdfNode parseObject(
            const std::vector<std::string> &tokens,
            std::size_t &position,
            bool expectClosingBrace)
        {
            VdfNode object;
            object.isObject = true;

            while (position < tokens.size())
            {
                if (tokens[position] == "}")
                {
                    if (!expectClosingBrace)
                    {
                        throw std::runtime_error("Unexpected closing brace in VDF");
                    }

                    ++position;
                    return object;
                }

                const std::string key = tokens[position++];

                if (position >= tokens.size())
                {
                    throw std::runtime_error("Missing value for VDF key: " + key);
                }

                VdfNode value;

                if (tokens[position] == "{")
                {
                    ++position;
                    value = parseObject(tokens, position, true);
                }
                else
                {
                    value.value = tokens[position++];
                }

                object.children[key] = std::move(value);
            }

            if (expectClosingBrace)
            {
                throw std::runtime_error("Missing closing brace in VDF");
            }

            return object;
        }

    }

    VdfNode VdfParser::parse(const std::string &content)
    {
        const auto tokens = tokenize(content);

        std::size_t position = 0;

        return parseObject(tokens, position, false);
    }

}