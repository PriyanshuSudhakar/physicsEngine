cd build

# 1. Run the application
if (Test-Path "Release\app.exe") {
    Write-Host "Starting app..." -ForegroundColor Green
    .\Release\app.exe
} else {
    Write-Error "Build failed or app.exe not found."
}

# Go back to root directory
cd ..