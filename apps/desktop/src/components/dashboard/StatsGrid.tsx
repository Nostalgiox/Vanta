import { Gamepad2, Cpu, Zap, Activity } from "lucide-react";

const stats = [
  {
    label: "INSTALLED GAMES",
    value: "08",
    description: "Games in your library",
    icon: Gamepad2,
  },
  {
    label: "SUPPORTED GAMES",
    value: "04",
    description: "With available trainers",
    icon: Cpu,
  },
  {
    label: "ACTIVE TRAINERS",
    value: "00",
    description: "Currently enabled",
    icon: Zap,
  },
  {
    label: "ENGINE STATUS",
    value: "READY",
    description: "Native engine initialized",
    icon: Activity,
  },
];

export function StatsGrid() {
  return (
    <section className="grid grid-cols-1 gap-4 sm:grid-cols-2 xl:grid-cols-4">
      {stats.map(({ label, value, description, icon: Icon }) => (
        <div
          key={label}
          className="rounded-xl border border-white/[0.06] bg-[#17191A] p-5 transition-colors hover:border-white/[0.12]"
        >
          <div className="flex items-center justify-between">
            <span className="text-[10px] font-semibold tracking-[0.16em] text-[#92979B]">
              {label}
            </span>

            <Icon size={18} className="text-[#B5F34D]" />
          </div>

          <p className="mt-5 text-2xl font-semibold tracking-tight text-white">
            {value}
          </p>

          <p className="mt-1 text-xs text-[#666D68]">
            {description}
          </p>
        </div>
      ))}
    </section>
  );
}
