# Set working variables.
set datafile cad/nist/nist_ctc_02.brep

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

# Check Euler-Poincare property of the manifold before modification.
if { [check-euler 8] != 1 } {
  error "Euler-Poincare property is not equal to the expected value."
}

# Kill blend face.
if { [kill-blend 175] != 1 } {
  error "Unexpected result of command."
}

# Kill blend face.
if { [kill-blend 171] != 1 } {
  error "Unexpected result of command."
}

# Kill blend face.
if { [kill-blend 169] != 1 } {
  error "Unexpected result of command."
}

# Kill blend face.
if { [kill-blend 163] != 1 } {
  error "Unexpected result of command."
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
