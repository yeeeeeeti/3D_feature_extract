# Set working variables.
set datafile cad/situ/vexity/situ_vexity_039.brep

# -1: undefined
#  0: concave
#  1: convex
#  2: smooth
set ref_vexity 0

# Read input geometry.
set datadir $env(ASI_TEST_DATA)
load-brep $datadir/$datafile
fit

# Check vexity.
set vexity [check-edge-vexity 4]

# Verify result.
if { $vexity != $ref_vexity } {
  error "Unexpected vexity ($ref_vexity expected while $vexity returned)."
}
