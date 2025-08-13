onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label SW0 -radix binary /testbench/FSM_input
add wave -noupdate -label SW9 -radix binary /testbench/Clock
add wave -noupdate -label Reset -radix binary /testbench/Reset
add wave -noupdate -divider hw5p2
add wave -noupdate -label LEDR0 -radix binary /testbench/OUT_LED
add wave -noupdate -label HEX5 -radix binary /testbench/OUT_sevSeg
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
