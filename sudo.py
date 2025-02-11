import os, sys

# Requires Administrator (sudo)
if os.geteuid() != 0:
    print("Program requires Administrator privileges. Restarting...")
    os.execvp("sudo", ["sudo", sys.executable] + sys.argv)

# Python
os.chdir(os.path.dirname(os.path.abspath(__file__)))

# Run Program main
print("Welcome, I'm Mohammed Al-Baqer")

# Simulate program execution
try:
    pass
except Exception as e:
    print(f"Failed to execute the program: {e}")
    input("Press Enter to exit...")
