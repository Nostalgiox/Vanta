import { Search, Bell } from "lucide-react";

export function Topbar() {
  return (
    <header className="flex h-[76px] items-center justify-between border-b border-white/[0.06] px-8">
      <div className="flex items-center gap-2 text-xs tracking-wider text-[#92979B]">
        <span>VANTA</span>
        <span>/</span>
        <span className="text-white">DASHBOARD</span>
      </div>

      <div className="flex items-center gap-5">
        <div className="flex items-center gap-2 rounded-lg border border-white/[0.08] bg-white/[0.02] px-3 py-2">
          <Search size={15} className="text-[#92979B]" />
          <span className="text-xs text-[#666D68]">
            Search...
          </span>
          <span className="ml-5 rounded border border-white/10 px-1.5 py-0.5 text-[10px] text-[#666D68]">
            /
          </span>
        </div>

        <button
          aria-label="Notifications"
          className="text-[#92979B] transition-colors hover:text-white"
        >
          <Bell size={18} />
        </button>

        <div className="flex h-9 w-9 items-center justify-center rounded-lg bg-[#252A27] text-xs font-semibold text-[#B5F34D]">
          DM
        </div>
      </div>
    </header>
  );
}
