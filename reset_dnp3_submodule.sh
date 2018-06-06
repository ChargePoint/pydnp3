git rm --cached deps/dnp3
rm -rf .git/modules/deps/dnp3
rm -rf deps/dnp3
cd deps
git submodule add https://github.com/automatak/dnp3.git
git submodule update --init --recursive
cd dnp3
git checkout 71e767f4c4baae8e866406b964d9e8ffaafa02d8
cd ../..