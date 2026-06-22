connect
targets -set -filter {name =~ "Cortex-A53 #0"}
rst -processor -clear-registers
dow C:/zynq_vitis2025/hello_world/build/hello_world.elf
targets -set -filter {name =~ "Cortex-A53 #1"}
rst -processor -clear-registers
dow C:/zynq_vitis2025/hello_core1/build/hello_core1.elf

targets -set -filter {name =~ "Cortex-A53 #1"}
con
targets -set -filter {name =~ "Cortex-A53 #0"}
con
