import ctypes, sys, os; os.system('cls' if os.name == 'nt' else 'clear')

# Requires Administrator
def Administrator():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False
    
if not Administrator():
    print("Program requires Administrator privileges")
    script = sys.executable
    params = " ".join([f'"{arg}"' for arg in sys.argv])
    ctypes.windll.shell32.ShellExecuteW(None, "runas", script, params, None, 1)
    sys.exit()

# python
os.chdir(os.path.dirname(os.path.abspath(__file__)))
# Run Program main

print("Welcome I'm Mohammed Al-Baqer")
try:
    pass

except Exception as e:
    print(f"Failed to execute the program: {e}")
    input("Press Enter to exit...")