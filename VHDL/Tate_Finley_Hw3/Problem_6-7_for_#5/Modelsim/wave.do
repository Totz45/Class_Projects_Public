onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label A -radix hexadecimal /testbench/A
add wave -noupdate -divider hw3p410
add wave -noupdate -label OUT_F /testbench/OUT_F
add wave -noupdate -label OUT_G /testbench/OUT_G
add wave -noupdate -label OUT_H /testbench/OUT_H
add wave -noupdate -label OUT_I /testbench/OUT_I
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
WaveRestoreZoom {0 ps} {260 ns}
