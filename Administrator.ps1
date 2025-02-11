# Requires Administrator
$adminCheck = [System.Security.Principal.WindowsPrincipal]`
    [System.Security.Principal.WindowsIdentity]::GetCurrent()
$adminRole = [System.Security.Principal.WindowsBuiltInRole]::Administrator

if (-not $adminCheck.IsInRole($adminRole)) {
    Write-Host "Program requires Administrator privileges. Restarting..."
    Start-Process -FilePath "powershell" -ArgumentList "-ExecutionPolicy Bypass -File `"$PSCommandPath`"" -Verb RunAs
    exit
}

# PowerShell
Set-Location -Path $PSScriptRoot

# Run Program main
Write-Host "Welcome I'm Mohammed Al-Baqer"

# Simulate program execution
try {
    # Your main program logic here
}
catch {
    Write-Host "Failed to execute the program: $_"
    Read-Host "Press Enter to exit..."
}