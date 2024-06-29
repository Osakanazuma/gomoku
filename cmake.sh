PROJECT_DIR="../gomoku"
BUILD_DIR="$PROJECT_DIR/build"

echo "Running CMake..."
cmake -G Ninja -B "$BUILD_DIR" "$PROJECT_DIR"

cd "$BUILD_DIR" || exit

echo "Building project with Ninja..."
ninja

if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
fi