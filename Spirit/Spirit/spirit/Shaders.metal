#include <metal_stdlib>

#include "math/Math.hpp"

using namespace metal;

#import "ShaderTypes.h"

// Vertex shader outputs and fragment shader inputs
typedef struct
{
    // The [[position]] attribute of this member indicates that this value
    // is the clip space position of the vertex when this structure is
    // returned from the vertex function.
    float4 position [[position]];

    // Since this member does not have a special attribute, the rasterizer
    // interpolates its value with the values of the other triangle vertices
    // and then passes the interpolated value to the fragment shader for each
    // fragment in the triangle.
    float4 color /*[[flat]]*/;

} RasterizerData;

vertex RasterizerData
vertexShader(uint vertexID [[vertex_id]],
             constant spirit::Vertex* vertices [[buffer(spirit::VertexInputIndex::Vertices)]],
             constant spirit::math::Size2* viewportSizePtr [[buffer(spirit::VertexInputIndex::ViewportSize)]])
{
    RasterizerData out;

    // Index into the array of positions to get the current vertex.
    // The positions are specified in pixel dimensions (i.e. a value of 100
    // is 100 pixels from the origin).
    float2 pixelSpacePosition = vertices[vertexID].position;

    // Get the viewport size and cast to float.
    auto viewportSize = *viewportSizePtr;
    

    // To convert from positions in pixel space to positions in clip-space,
    //  divide the pixel coordinates by half the size of the viewport.
    out.position = vector_float4(0.0, 0.0, 0.0, 1.0);
    out.position.xy = pixelSpacePosition / (viewportSize / 2.0);

    // Pass the input color directly to the rasterizer.
    out.color = vertices[vertexID].color;

    return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]])
{
    // Return the interpolated color.
    return in.color;
}

