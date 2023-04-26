#include <windows.h>
/// week11-3_PlaySound.cpp 如果沒有手動加上lib就無法正常執行
///setting-compiler-->linker setting --> add "winmm" 這個lib


int main()
{
                              ///要等待同步
    PlaySound("do_re_mi\\do.wav",NULL,SND_SYNC);
    PlaySound("do_re_mi\\re.wav",NULL,SND_SYNC);
    PlaySound("do_re_mi\\mi.wav",NULL,SND_SYNC);
    PlaySound("do_re_mi\\do.wav",NULL,SND_SYNC);

}

///Checking for existence: C:\Users\Administrator\Desktop\week11-3_PlaySound.exe
///Executing: '"C:\Program Files (x86)\CodeBlocks/cb_console_runner.exe" "C:\Users\Administrator\Desktop\week11-3_PlaySound.exe"' (in 'C:\Users\Administrator\Desktop')
///由上列的資訊可以得知，這個執行檔的執行目錄是在C:\Users\Administrator\Desktop下面，所以在這種情況下要撥放音樂可以使用"相對路徑"

