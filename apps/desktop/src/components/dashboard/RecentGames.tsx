import { ArrowUpRight, Gamepad2 } from "lucide-react";

const games = [
  {
    name: "Remnant II",
    category: "Action RPG",
    status: "SUPPORTED",
    color: "text-[#B5F34D]",
  },
  {
    name: "Elden Ring",
    category: "Action RPG",
    status: "SUPPORTED",
    color: "text-[#B5F34D]",
  },
  {
    name: "Cyberpunk 2077",
    category: "Open World RPG",
    status: "SUPPORTED",
    color: "text-[#B5F34D]",
  },
];

export function RecentGames() {
  return (
    <section className="rounded-xl border border-white/[0.06] bg-[#17191A]">
      <div className="flex items-center justify-between border-b border-white/[0.06] p-5">
        <div>
          <h2 className="text-sm font-semibold text-white">
            Your games
          </h2>
          <p className="mt-1 text-xs text-[#666D68]">
            Recently added to your library
          </p>
        </div>

        <button className="flex items-center gap-2 text-xs text-[#B5F34D] hover:text-white">
          View library
          <ArrowUpRight size={14} />
        </button>
      </div>

      <div className="divide-y divide-white/[0.04]">
        {games.map((game) => (
          <div
            key={game.name}
            className="flex items-center gap-4 px-5 py-4 transition-colors hover:bg-white/[0.02]"
          >
            <div className="flex h-11 w-11 items-center justify-center rounded-lg bg-[#252A27]">
              <Gamepad2 size={20} className="text-[#B5F34D]" />
            </div>

            <div className="min-w-0 flex-1">
              <p className="truncate text-sm font-medium text-white">
                {game.name}
              </p>
              <p className="mt-1 text-xs text-[#666D68]">
                {game.category}
              </p>
            </div>

            <span className={`text-[9px] font-semibold tracking-wider ${game.color}`}>
              {game.status}
            </span>
          </div>
        ))}
      </div>
    </section>
  );
}
