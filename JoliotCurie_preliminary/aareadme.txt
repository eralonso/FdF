Readme file for PRELIMINARY USGS Magellan stereo DEMs.

This directory contains DEMs and corresponding color-coded shaded relief map,
contour map and orthoimages based on the 12x12 degree Magellan FMAP (USGS
full-resolution mosaic) quadrangle series.  Gaps exist in the stereo coverge,
so Magellan Altimetry data is used as gap fill in the merged DEM product
The merged DEM was used to generate a color-coded shaded relief image/map and
200 meter contour map with the cycle-1 FMAP orthorectified (i.e., map projected
with removal of topographic parallax) mosaic as the image base.  All products
are in sinusoidal map projection, addtionally the color-coded shaded relief map
and contour map are at a scale of 1:1,500,000.

Projection Parameters:
Sinusoidal
Central_Meridian 66.0
SPHERE Semi-major and minor axis, Venus_1985_IAU_IAG_COSPAR 6051000.0


General considerations on files:  DEMs are included as ISIS cubes and as
Arc/Info and ArcMap Grids and ASCII Grids. (See ASCII grid explanation at bottom).
Orthoimage files are included as ISIS cubes and Jpeg files with accompanying
georeferencing world files (*.jgw).  Shaded relief images are included as
RGB color geo-TIFF images plus associated world files.  DEMs are 32-bit 
floating point in units of meters; values in DEMs are heights 
relative to the Venus 1985 figure (sphere with radius of 6051 km). Orthoimages are
8-bit. Pixels outside of the spatial extent of the data have ISIS nonvalid values,
which will be 0 for the images, NULL (-340282265508890445205022487695511781376.0)
for the DEMs.  The orthoimage have pixel scale of 75 m. DEMs and shaded relief
images have a scale of 675 m/post ("post" = DEM pixel).


Schemes used for directories are as follows:
Directory of JoliotCurie_preliminary:
arc_dems/		ArcMap GIS DEM Grids and ASCII DEMS
maps/			Contour and shaded releif maps as JPEG images (preliminary 150dpi)
isis_dems/		DEMS in ISIS (*.cub) format
isis_ortho_images/	Orthoimages in ISIS (*.cub) format
    removed from this compression set but can be downloaded separately
jpeg_ortho_images/       Orthoimages in JPEG format plus world files
shadedreliefs/		geo-TIFF images of color-coded shaded relief DEMs
                        with world files. (preliminary)


Schemes used for filenames are as follows:

{fmap_name}{x}_stereo_ortho.cub = 75 m/pixel orthoimage based on stereo coverage
{fmap_name}{x}_mrg_ortho.cub = 75 m/pixel orthoimage based on stereo plus altimetry
                               coverage

{fmap_name}_stereo.cub = 675 m/post stereo DEM
{fmap_name}_mrg.cub = 657 m/post stereo DEM plus Magellan Altimetry for gap fill

{fmap_name}_stereo_hillshade.tif = 675 m/pixel color-coded shaded relief image
                                   of stereo DEM coverage
{fmap_name}_mrg_hillshade.tif = 675 m/pixel color-coded shaded relief image of
                                stereo DEM merged with Magellan Altimetry as
                                gap fill.


Variable parts of filename have been placed in braces {}. {fmap_name} is the name assigned
to the F-MAP quadrangle.  {x} may be absent or is 1 or 3 for cycle-1 or cycle-3 Magellan
image source.


------------------------------
Arc/Info, ArcMap ASCII Grid:
The first six lines of an ArcView-compatible ASCII grid data file are header 
parameters that control the georeferencing of the grid.  The rest of the file is 
just cell Z-values, since the X and Y coordinates of each grid cell are 
determined from the header.  A typical ArcMap ASCII grid file header looks like 
this: 

ncols 363 
nrows 465 
xllcorner 424881   (or you can specify xllcenter) 
yllcorner 4386413  (or you can specify yllcenter) 
cellsize 30 
nodata_value -9999 (so that zero can be a valid cell value)
   (363 x 465 = 168,795 cell Z-values follow....) 

If you need a different ASCII file format, use a plain text editor to remove or 
edit the header lines.

Contact:Trent Hare
thare@usgs.gov
928-556-7126