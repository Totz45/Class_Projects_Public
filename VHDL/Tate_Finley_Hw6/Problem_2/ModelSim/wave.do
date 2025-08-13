onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label Count_rst -radix binary /testbench/Switch
add wave -noupdate -label Count -radix hexadecimal /testbench/counter
add wave -noupdate -label Clock_sig -radix binary /testbench/Clock_16Mhz
add wave -noupdate -divider hw6p2
add wave -noupdate -label LED0 -radix binary /testbench/LEDR0
add wave -noupdate -label Clicks -radix binary /testbench/Buzzer
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {80000 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 80
configure wave -valuecolwidth 40
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {50 ms}
