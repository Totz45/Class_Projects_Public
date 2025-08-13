onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label Switch_3-0 -radix binary /testbench/A
add wave -noupdate -label Pushbutton_1-0 -radix binary /testbench/Pushbutton
add wave -noupdate -divider hw3p42
add wave -noupdate -label OUT_F1 /testbench/OUT_F
add wave -noupdate -label OUT_F2 /testbench/OUT_G
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
