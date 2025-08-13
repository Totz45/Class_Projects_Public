onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label inData -radix binary /testbench/A
add wave -noupdate -label blanking -radix binary /testbench/blank
add wave -noupdate -label dispHex -radix binary /testbench/hexValue
add wave -noupdate -label dispPoint -radix binary /testbench/point
add wave -noupdate -divider bin2seg7
add wave -noupdate -label seg_A /testbench/OUT_A
add wave -noupdate -label seg_B /testbench/OUT_B
add wave -noupdate -label seg_C /testbench/OUT_C
add wave -noupdate -label seg_D /testbench/OUT_D
add wave -noupdate -label seg_E /testbench/OUT_E
add wave -noupdate -label seg_F /testbench/OUT_F
add wave -noupdate -label seg_G /testbench/OUT_G
add wave -noupdate -label seg_Point /testbench/OUT_Point
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
