#include <windows.h>
/// week11-3_PlaySound.cpp �p�G�S����ʥ[�Wlib�N�L�k���`����
///setting-compiler-->linker setting --> add "winmm" �o��lib


int main()
{
                              ///�n���ݦP�B
    PlaySound("do_re_mi\\do.wav",NULL,SND_SYNC);
    PlaySound("do_re_mi\\re.wav",NULL,SND_SYNC);
    PlaySound("do_re_mi\\mi.wav",NULL,SND_SYNC);
    PlaySound("do_re_mi\\do.wav",NULL,SND_SYNC);

}

///Checking for existence: C:\Users\Administrator\Desktop\week11-3_PlaySound.exe
///Executing: '"C:\Program Files (x86)\CodeBlocks/cb_console_runner.exe" "C:\Users\Administrator\Desktop\week11-3_PlaySound.exe"' (in 'C:\Users\Administrator\Desktop')
///�ѤW�C����T�i�H�o���A�o�Ӱ����ɪ�����ؿ��O�bC:\Users\Administrator\Desktop�U���A�ҥH�b�o�ر��p�U�n���񭵼֥i�H�ϥ�"�۹���|"

