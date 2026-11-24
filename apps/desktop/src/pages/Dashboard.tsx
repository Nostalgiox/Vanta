import { WelcomeSection } from "../components/dashboard/WelcomeSection";
import { StatsGrid } from "../components/dashboard/StatsGrid";
import { EngineStatus } from "../components/dashboard/EngineStatus";
import { RecentGames } from "../components/dashboard/RecentGames";

export function Dashboard() {
  return (
    <div className="space-y-8">
      <WelcomeSection />
      <StatsGrid />

      <div className="grid grid-cols-1 gap-5 xl:grid-cols-[1.5fr_1fr]">
        <RecentGames />
        <EngineStatus />
      </div>
    </div>
  );
}
