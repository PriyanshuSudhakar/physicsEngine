# 1. Clean up: Delete the build folder if it exists
if (Test-Path "build") {
    Write-Host "Cleaning up old build..." -ForegroundColor Yellow
    Remove-Item -Path "build" -Recurse -Force
}

# 2. Create a fresh build directory
New-Item -ItemType Directory -Path "build" | Out-Null
cd build

# 3. Configure CMake with vcpkg
Write-Host "Configuring CMake..." -ForegroundColor Blue
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake

# 4. Build the project
Write-Host "Building project..." -ForegroundColor Blue
cmake --build . --config Release --parallel

# 5. Run the application
if (Test-Path "Release\app.exe") {
    Write-Host "Starting app..." -ForegroundColor Green
    .\Release\app.exe
} else {
    Write-Error "Build failed or app.exe not found."
}

# Go back to root directory
cd ..


