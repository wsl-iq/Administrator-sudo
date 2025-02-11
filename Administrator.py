import os; os.system('cls' if os.name == 'nt' else 'clear')
import sys
import ctypes

R = "\033[91;1m"  # Red
G = "\033[92;1m"  # Green
B = "\033[94;1m"  # Blue
Y = "\033[93;1m"  # Yellow
C = "\033[96;1m"  # Cyan
M = "\033[95;1m"  # Magenta
W = "\033[97;1m"  # White
D = "\033[90;1m"  # Grey
S = "\033[0m"     # Reset

ERROR = "\033[93;1m" + "[" + "\033[91;1m" + "ERROR" + "\033[93;1m" + "]" + "\033[91;1m"
sign = "\033[92;1m" + "[" + "\033[94;1m" + "*" + "\033[92;1m" + "]" + "\033[94;1m"
INFO = "\033[93;1m" + "[" + "\033[92;1m" + "INFO" + "\033[93;1m" + "]" + "\033[94;1m"

def administrator():
    f"""{W}
    (Run this program as an administrator)
    """
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False


def RunAsAdministrator(executable_path):
    try:
        ctypes.windll.shell32.ShellExecuteW(
            None, "runas", executable_path, None, None, 1
        )
    except Exception as e:
        print(f"{ERROR} Operation Error {M}{executable_path} {R}with Administrator!{W}")
        sys.exit(1)

if __name__ == "__main__":
    # Location program for run by Administrator
    file_path = "app\\ManagerPc.py"

    if not administrator():
        print(f"{sign} Program required {Y}Manager pc {B}with Administrator...{W}")
        RunAsAdministrator(file_path)
        sys.exit(0)
    print(f"{INFO} Operation Successful {Y}Manager pc {B}with Administrator.")