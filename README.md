これは五目並べのコードです。
linux環境でしか、操作確認をしていませんが他のOSでも動かせるはずです。
ファイルの量が多いのでcmakeを使うことをおすすめします。
そして、シェルをつかうととても楽でいいですよ^^

例
cmake.sh
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

run.sh
EXECUTABLE_PATH="build/Gomoku"

echo "Running CMake..."
$EXECUTABLE_PATH

これを追加できたら
sh cmake.sh （コンパイル）
sh run.sh   （実行）
で実行できるはずです