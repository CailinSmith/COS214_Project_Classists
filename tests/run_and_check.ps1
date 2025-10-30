param(
    [string]$case = "case2"
)

# Build the project
Write-Host "Building project..."
cd $PSScriptRoot\..\
$make = Start-Process -FilePath make -NoNewWindow -PassThru -Wait
if ($make.ExitCode -ne 0) {
    Write-Error "Build failed with exit code $($make.ExitCode)"
    exit $make.ExitCode
}

$input = "$PSScriptRoot\inputs\$case.txt"
$output = "$PSScriptRoot\outputs\$case.out"
$expected = "$PSScriptRoot\expected\$case.txt"

if (-not (Test-Path $input)) { Write-Error "Input file $input not found"; exit 2 }
if (-not (Test-Path $expected)) { Write-Error "Expected patterns $expected not found"; exit 2 }

Write-Host "Running test case $case..."
# Run the main binary with redirected stdin and capture stdout
$exe = "$PSScriptRoot\..\build\main"
if (-not (Test-Path $exe)) { Write-Error "Executable $exe not found. Have you built?"; exit 3 }

Get-Content $input | & $exe > $output

Write-Host "Checking output against expected patterns..."
python -u "$PSScriptRoot\checker.py" $expected $output
$rc = $LASTEXITCODE
if ($rc -eq 0) { Write-Host "TEST PASSED" } else { Write-Error "TEST FAILED" }
exit $rc
