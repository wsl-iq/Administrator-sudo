#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int IsAdministrator() {
    BOOL isAdmin = FALSE;
    PSID adminGroup;
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS,
                                 0, 0, 0, 0, 0, 0, &adminGroup)) {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }
    return isAdmin;
}

void RunAsAdministrator() {
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    SHELLEXECUTEINFOA sei = { sizeof(sei) };
    sei.lpVerb = "runas";
    sei.lpFile = exePath;
    sei.nShow = SW_SHOWNORMAL;

    if (!ShellExecuteExA(&sei)) {
        printf("Failed to elevate privileges.\n");
    }
}

int main() {
    system("cls");

    if (!IsAdministrator()) {
        printf("Program requires Administrator privileges\n");
        RunAsAdministrator();
        return 0;
    }

    printf("Welcome I'm Mohammed Al-Baqer\n");

    try {
    } catch (...) {
        printf("Failed to execute the program.\n");
        system("pause");
    }

    return 0;
}
