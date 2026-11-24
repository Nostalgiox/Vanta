import { Activity, Terminal, CheckCircle2 } from "lucide-react";

export function EngineStatus() {
  return (
    <section className="rounded-xl border border-white/[0.06] bg-[#17191A] p-6">
      <div className="flex items-center justify-between">
        <div>
          <p className="text-[10px] font-semibold tracking-[0.18em] text-[#92979B]">
            NATIVE ENGINE
          </p>

          <h2 className="mt-2 text-lg font-semibold text-white">
            Engine overview
          </h2>
        </div>

        <div className="flex items-center gap-2 rounded-full border border-[#B5F34D]/20 bg-[#B5F34D]/10 px-3 py-1.5">
          <span className="h-1.5 w-1.5 rounded-full bg-[#B5F34D]" />
          <span className="text-[10px] font-semibold text-[#B5F34D]">
            INITIALIZED
          </span>
        </div>
      </div>

      <div className="mt-6 grid grid-cols-1 gap-4 sm:grid-cols-3">
        <div className="flex items-center gap-3">
          <div className="rounded-lg bg-white/[0.04] p-3">
            <Activity size={18} className="text-[#B5F34D]" />
          </div>

          <div>
            <p className="text-xs text-[#666D68]">Runtime</p>
            <p className="text-sm font-medium text-white">C++20</p>
          </div>
        </div>

        <div className="flex items-center gap-3">
          <div className="rounded-lg bg-white/[0.04] p-3">
            <Terminal size={18} className="text-[#B5F34D]" />
          </div>

          <div>
            <p className="text-xs text-[#666D68]">Protocol</p>
            <p className="text-sm font-medium text-white">STDIN / STDOUT</p>
          </div>
        </div>

        <div className="flex items-center gap-3">
          <div className="rounded-lg bg-white/[0.04] p-3">
            <CheckCircle2 size={18} className="text-[#B5F34D]" />
          </div>

          <div>
            <p className="text-xs text-[#666D68]">Platform</p>
            <p className="text-sm font-medium text-white">Linux</p>
          </div>
        </div>
      </div>
    </section>
  );
}
