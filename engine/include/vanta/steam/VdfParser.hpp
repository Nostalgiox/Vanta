#pragma once

#include <map>
#include <string>

namespace vanta::steam
{
    struct VdfNode
    {
        std::string value;
        std::map<std::string, VdfNode> children;

        bool isObject = false;

        const VdfNode *get(const std::string &key) const;
    };

    class VdfParser
    {
    public:
        static VdfNode parse(const std::string &content);
    };

}