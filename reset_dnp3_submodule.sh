git rm --cached deps/dnp3
rm -rf .git/modules/deps/dnp3
rm -rf deps/dnp3
cd deps
git submodule add https://github.com/automatak/dnp3.git
git submodule update --init --recursive
cd ..