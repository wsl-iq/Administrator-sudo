using System;
using System.Diagnostics;
using System.Security.Principal;
using System.Windows.Forms;

class Program {
    static bool IsAdministrator() {
        using (WindowsIdentity identity = WindowsIdentity.GetCurrent()) {
            WindowsPrincipal principal = new WindowsPrincipal(identity);
            return principal.IsInRole(WindowsBuiltInRole.Administrator);
        }
    }

    static void RunAsAdministrator() {
        ProcessStartInfo psi = new ProcessStartInfo {
            FileName = Application.ExecutablePath,
            Verb = "runas",
            UseShellExecute = true
        };
        try {
            Process.Start(psi);
        } catch {
            Console.WriteLine("Failed to elevate privileges.");
        }
    }

    [STAThread]
    static void Main() {
        Console.Clear();

        if (!IsAdministrator()) {
            Console.WriteLine("Program requires Administrator privileges");
            RunAsAdministrator();
            return;
        }

        Console.WriteLine("Welcome I'm Mohammed Al-Baqer");

        try {
        } catch (Exception e) {
            Console.WriteLine("Failed to execute the program: " + e.Message);
            Console.ReadLine();
        }
    }
}
