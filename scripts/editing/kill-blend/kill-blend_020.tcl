# Set working variables.
set datafile cad/sheet-metal/azv_clamp.brep

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
if { [check-euler 3] != 1 } {
  error "Euler-Poincare property is not equal to the expected value."
}

# Kill-blends.
if { [kill-blend 17] != 1 } {
  error "Unexpected result of command."
}
#
if { [kill-blend 12] != 1 } {
  error "Unexpected result of command."
}
#
if { [kill-blend 6] != 1 } {
  error "Unexpected result of command."
}

# Check Euler-Poincare property of the manifold.
if { [check-euler 3] != 1 } {
  error "Euler-Poincare property does not hold after topological modification."
}

# Check orientations of vertices.
if { [check-vertices-ori] != 1 } {
  error "Some edges have non-distinguishable orientations of vertices."
}

# Check contours of faces.
if { [check-contours] != 1 } {
  error "Some faces have open contours."
}

# Check validity of the result.
if { [check-validity] != 1 } {
  error "Final part is not valid."
}

# Check that tolernace has not significantly degraded.
set finalToler [get-tolerance]
puts "Final tolerance ($finalToler) vs initial tolerance ($initialToler)"
#
if { [expr $finalToler - $initialToler] > 1e-3 } {
  error "Significant tolerance degradation."
}
