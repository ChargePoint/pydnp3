git rm --cached deps/pybind11
rm -rf .git/modules/deps/pybind11
rm -rf deps/pybind11
cd deps
git submodule add https://github.com/Kisensum/pybind11.git
git submodule update --init --recursive
cd ..