import {
  LayoutDashboard,
  Gamepad2,
  Cpu,
  Settings,
  Zap,
} from "lucide-react";

const navigation = [
  { label: "Dashboard", icon: LayoutDashboard },
  { label: "Game Library", icon: Gamepad2 },
  { label: "Trainers", icon: Cpu },
];

export function Sidebar() {
  return (
    <aside className="flex h-screen w-64 shrink-0 flex-col border-r border-white/[0.06] bg-[#131515] px-5 py-6">
      <div className="mb-12 flex items-center gap-3">
        <div className="flex h-9 w-9 items-center justify-center rounded-lg bg-[#B5F34D]">
          <Zap className="h-5 w-5 text-[#101112]" />
        </div>

        <span className="text-xl font-bold tracking-[0.2em] text-white">
          VANTA
        </span>
      </div>

      <p className="mb-4 px-3 text-[10px] font-semibold tracking-[0.2em] text-[#666D68]">
        WORKSPACE
      </p>

      <nav className="space-y-1">
        {navigation.map(({ label, icon: Icon }, index) => (
          <button
            key={label}
            className={`flex w-full items-center gap-3 rounded-lg px-3 py-3 text-sm transition-colors ${
              index === 0
                ? "bg-[#B5F34D]/10 text-[#B5F34D]"
                : "text-[#92979B] hover:bg-white/[0.04] hover:text-white"
            }`}
          >
            <Icon size={18} />
            {label}
          </button>
        ))}
      </nav>

      <div className="mt-auto">
        <button className="flex w-full items-center gap-3 rounded-lg px-3 py-3 text-sm text-[#92979B] transition-colors hover:bg-white/[0.04] hover:text-white">
          <Settings size={18} />
          Settings
        </button>

        <div className="mt-5 border-t border-white/[0.06] pt-5">
          <p className="text-[10px] tracking-wider text-[#666D68]">
            VANTA ENGINE
          </p>
          <div className="mt-3 flex items-center gap-2">
            <span className="h-2 w-2 rounded-full bg-[#B5F34D]" />
            <span className="text-xs text-[#92979B]">
              Engine initialized
            </span>
          </div>
        </div>
      </div>
    </aside>
  );
}
