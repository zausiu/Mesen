#include <iostream>
#include <memory>
#include <assert.h>
#include "Console.h"
#include "EmulationSettings.h"
#include "DebuggerTypes.h"
#include "../Utilities/FolderUtilities.h"

int main(int argc, char**)
{
    using namespace std;

    const VideoFilterType filterTypes[13] = { VideoFilterType::BisqwitNtscQuarterRes, VideoFilterType::HQ2x, VideoFilterType::HQ3x, VideoFilterType::HQ4x, VideoFilterType::NTSC, VideoFilterType::Scale2x, VideoFilterType::Scale3x, VideoFilterType::Scale4x, VideoFilterType::xBRZ2x, VideoFilterType::xBRZ3x, VideoFilterType::xBRZ4x, VideoFilterType::xBRZ5x, VideoFilterType::xBRZ6x };
    FolderUtilities::SetHomeFolder("/home/kamus/tmp/thug/");

    const char* rom_filepath = "../thug/SuperMarioBros.nes";
    std::cout << "Running: " << rom_filepath << std::endl;

    shared_ptr<Console> console(new Console());
    console->Init();
    bool ok = console->Initialize(rom_filepath);
    assert(ok);
    console->GetSettings()->SetFlags(EmulationFlags::ConsoleMode | EmulationFlags::UseHdPacks);
    console->GetSettings()->SetVideoFilterType(filterTypes[0]);

    if(false) {
        // console->GetDebugger(true)->SetFlags((uint32_t)DebuggerFlags::BreakOnFirstCycle);
    }

    // thread testThread([&console] {
        console->Run();
    // });
    std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(50000 * 10000));
    console->Stop();
    // testThread.join();
    console->Release(true);


    cout << "quit...\n";
}
