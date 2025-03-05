#include <windows.h>
#include <iostream>

void RunAsAdministrator() {
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    SHELLEXECUTEINFOA sei = { sizeof(sei) };
    sei.lpVerb = "runas";
    sei.lpFile = exePath;
    sei.nShow = SW_SHOWNORMAL;

    if (!ShellExecuteExA(&sei)) {
        std::cout << "Failed to elevate privileges.\n";
    }
}

bool IsAdministrator() {
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

int main() {
    system("cls");

    if (!IsAdministrator()) {
        std::cout << "Program requires Administrator privileges\n";
        RunAsAdministrator();
        return 0;
    }

    std::cout << "Welcome I'm Mohammed Al-Baqer\n";

    try {
    } catch (const std::exception& e) {
        std::cerr << "Failed to execute the program: " << e.what() << std::endl;
        system("pause");
    }

    return 0;
}
