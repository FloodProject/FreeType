#ifndef __AFLATIN_H__
#define __AFLATIN_H__

#include "afhints.h"

FT_BEGIN_HEADER
 
 /* 
  * the latin-specific script class
  *
  */
  FT_LOCAL( const FT_ScriptClassRec )    af_latin_script_class;

 /***************************************************************************/
 /***************************************************************************/
 /*****                                                                 *****/
 /*****       L A T I N   G L O B A L   M E T R I C S                   *****/
 /*****                                                                 *****/
 /***************************************************************************/
 /***************************************************************************/

 /*
  * the following declarations could be embedded in the file "aflatin.c"
  * they've been made semi-public to allow alternate script hinters to
  * re-use some of them
  */

 /*
  *  Latin (global) metrics management
  *
  */

  enum
  {
    AF_LATIN_BLUE_CAPITAL_TOP,
    AF_LATIN_BLUE_CAPITAL_BOTTOM,
    AF_LATIN_BLUE_SMALL_F_TOP,
    AF_LATIN_BLUE_SMALL_TOP,
    AF_LATIN_BLUE_SMALL_BOTTOM,
    AF_LATIN_BLUE_SMALL_MINOR,
    
    AF_LATIN_BLUE_MAX
  };

#define AF_LATIN_IS_TOP_BLUE( b )  ( (b) == AF_LATIN_BLUE_CAPITAL_TOP || \
                                     (b) == AF_LATIN_BLUE_SMALL_F_TOP || \
                                     (b) == AF_LATIN_BLUE_SMALL_TOP   )

#define  AF_LATIN_MAX_WIDTHS     16
#define  AF_LATIN_MAX_BLUES      AF_LATIN_BLUE_MAX

  enum
  {
    AF_LATIN_BLUE_ACTIVE = (1 << 0),
    AF_LATIN_BLUE_TOP    = (1 << 1),
    
    AF_LATIN_BLUE_MAX
  };


  typedef struct AF_LatinBlueRec_
  {
    AF_WidthRec   ref;
    AF_WidthRec   shoot;
    FT_UInt       flags;
  
  } AF_LatinBlueRec, *AF_LatinBlue;


  typedef struct AF_LatinAxisRec_
  {
    FT_Fixed         scale;
    FT_Pos           delta;
    
    FT_UInt          width_count;
    AF_WidthRec      widths[ AF_LATIN_MAX_WIDTHS ];
    FT_Pos           edge_distance_threshold;
    
   /* ignored for horizontal metrics */
    FT_Bool          control_overshoot;
    FT_UInt          blue_count;
    AF_LatinBlueRec  blues;

  } AF_LatinAxisRec, *AF_LatinAxis;


  typedef struct AF_LatinMetricsRec_
  {
    AF_ScriptMetricsRec   root;
    FT_UInt               units_per_em;
    AF_LatinAxisRec       axis[ AF_DIMENSION_MAX ];
  
  } AF_LatinMetricsRec, *AF_LatinMetrics;


  FT_LOCAL( FT_Error )
  af_latin_metrics_init( AF_LatinMetrics  metrics,
                         FT_Face          face );

  FT_LOCAL( void )
  af_latin_metrics_scale( AF_LatinMetrics  metrics,
                          AF_Scaler        scaler );



 /***************************************************************************/
 /***************************************************************************/
 /*****                                                                 *****/
 /*****            L A T I N   G L Y P H   A N A L Y S I S              *****/
 /*****                                                                 *****/
 /***************************************************************************/
 /***************************************************************************/


 /* this shouldn't normally be exported. However, other scripts might
  * like to use this function as-is
  */
  FT_LOCAL( void )
  af_latin_hints_compute_segments( AF_GlyphHints  hints,
                                   AF_Dimension   dim );

 /* this shouldn't normally be exported. However, other scripts might
  * want to use this function as-is
  */
  FT_LOCAL( void )
  af_latin_hints_link_segments( AF_GlyphHints  hints,
                                AF_Dimension   dim );

 /* this shouldn't normally be exported. However, other scripts might
  * want to use this function as-is
  */
  FT_LOCAL( void )
  af_latin_hints_compute_edges( AF_GlyphHints  hints,
                                AF_Dimension   dim );

  FT_LOCAL( void )
  af_latin_hints_detect_features( AF_GlyphHints  hints,
                                  AF_Dimension   dim );

/* */

FT_END_HEADER

#endif /* __AFLATIN_H__ */