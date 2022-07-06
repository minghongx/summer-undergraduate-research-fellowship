catkin build go1_description
apt install ros-noetic-xacro ros-noetic-joint-state-publisher

google 搜 clangd --compile-commands-dir multiple 能给我搜到 2019 年的 ocs2
https://gitter.im/Valloric/YouCompleteMe?at=5dceca65eeb63e1a83bb35e7

catkin build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ocs2
https://github.com/catkin/catkin_tools/issues/551
catkin config --cmake-args='-DCMAKE_EXPORT_COMPILE_COMMANDS=ON'

"cmake.copyCompileCommands": "${workspaceFolder}/compile_commands.json"
This copies the compile_commands.json of the build dir to workspace folder, which in my case happens to be where clangd is looking for the compile_commands.json file.

boost::property_tree::read_info(filename, pt);
