import { ArrowUpRight } from "lucide-react";

export function WelcomeSection() {
  return (
    <section className="flex items-end justify-between">
      <div>
        <p className="mb-3 text-xs font-semibold tracking-[0.2em] text-[#B5F34D]">
          YOUR GAMING ENVIRONMENT
        </p>

        <h1 className="text-3xl font-semibold tracking-tight text-white">
          Welcome back.
        </h1>

        <p className="mt-2 text-sm text-[#92979B]">
          Everything you need to manage your gaming experience.
        </p>
      </div>

      <button className="flex items-center gap-2 rounded-lg bg-[#B5F34D] px-4 py-2.5 text-xs font-semibold text-[#101112] transition-colors hover:bg-[#c5ff65]">
        Explore library
        <ArrowUpRight size={15} />
      </button>
    </section>
  );
}
