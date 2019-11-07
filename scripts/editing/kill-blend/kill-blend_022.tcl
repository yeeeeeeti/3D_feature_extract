# Set working variables.
set datafile cad/sheet-metal/sheet_metal_54_prepared.brep

# Read input geometry.
set datadir $env(ASI_TEST_DATA)
load-brep $datadir/$datafile
fit
#
if { [check-validity] != 1 } {
  error "Initial part is not valid."
}
#
print-summary
#
set initialToler [get-tolerance]

# Check Euler-Poincare property of the manifold before modification.
if { [check-euler 0] != 1 } {
  error "Euler-Poincare property is not equal to the expected value."
}

disable-notifier

# Attempt to kill blend.
if { [kill-blend 16] == 1 } {
  error "Unexpected result of blend suppression (failure expected)."
}
#
if { [kill-blend 24] == 1 } {
  error "Unexpected result of blend suppression (failure expected)."
}
#
if { [kill-blend 20] == 1 } {
  error "Unexpected result of blend suppression (failure expected)."
}
#
if { [kill-blend 25] == 1 } {
  error "Unexpected result of blend suppression (failure expected)."
}

enable-notifier