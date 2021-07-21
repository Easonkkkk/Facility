copy mscomm*.* C:\Windows\SysWOW64\ /y
regsvr32 /u C:\WINDOWS\SysWOW64\MSCOMM32.OCX
regsvr32 /i C:\WINDOWS\SysWOW64\MSCOMM32.OCX
regsvr32 C:\WINDOWS\SysWOW64\MSCOMM32.OCX
Regedit_MSCOMM32.reg
pause