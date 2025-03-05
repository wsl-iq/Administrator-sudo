using System;
using System.Diagnostics;
using System.IO;
using System.Linq;

class Program {
    static void RunAsAdministrator() {
        Console.WriteLine("Program requires Administrator privileges. Restarting...");
        Process.Start("sudo", "dotnet " + System.Reflection.Assembly.GetExecutingAssembly().Location);
    }

    static void Main() {
        if (Environment.UserName != "root") {
            RunAsAdministrator();
            return;
        }

        Console.WriteLine("Welcome, I'm Mohammed Al-Baqer");

        try {
        } catch (Exception e) {
            Console.WriteLine("Failed to execute the program: " + e.Message);
            Console.ReadLine();
        }
    }
}
