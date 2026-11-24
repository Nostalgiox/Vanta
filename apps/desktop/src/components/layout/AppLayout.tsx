import { Sidebar } from "./Sidebar";
import { Topbar } from "./Topbar";
import { Dashboard } from "../../pages/Dashboard";

export function AppLayout() {
  return (
    <div className="flex min-h-screen bg-[#101112]">
      <Sidebar />

      <main className="min-w-0 flex-1">
        <Topbar />

        <div className="mx-auto max-w-[1600px] p-8">
          <Dashboard />
        </div>
      </main>
    </div>
  );
}
