//
//  Shaders.metal
//  Spirit
//
//  Created by Vanush Grigoryan on 6/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include <metal_stdlib>

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
    
    float pointSize [[point_size]];

} RasterizerData_P;

vertex RasterizerData_P
vertexShader_P(uint vertexID [[vertex_id]],
             constant spirit::Vertex_P* vertices [[buffer(spirit::kVertexInputIndexVertices)]],
             constant float2* viewportSizePtr [[buffer(spirit::kVertexInputIndexViewportSize)]])
{
    RasterizerData_P out;

    // Index into the array of positions to get the current vertex.
    // The positions are specified in pixel dimensions (i.e. a value of 100
    // is 100 pixels from the origin).
    float2 pixelSpacePosition = vertices[vertexID].position;

    // Get the viewport size and cast to float.
    auto viewportSize = *viewportSizePtr;
    

    // To convert from positions in pixel space to positions in clip-space,
    //  divide the pixel coordinates by half the size of the viewport.
    out.position = vector_float4(0.0, 0.0, 0.0, 1.0);
    out.position.xy = 2.f * (pixelSpacePosition / viewportSize) - 1.f;
    
    out.pointSize = 10.0;

    return out;
}

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
    
    float pointSize [[point_size]];

} RasterizerData;

vertex RasterizerData
vertexShader(uint vertexID [[vertex_id]],
             constant spirit::Vertex* vertices [[buffer(spirit::kVertexInputIndexVertices)]],
             constant float2* viewportSizePtr [[buffer(spirit::kVertexInputIndexViewportSize)]])
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

vertex RasterizerData
durerVertexShader(uint vertexID [[vertex_id]],
             constant spirit::Vertex3d* vertices [[buffer(spirit::kVertexInputIndexVertices)]],
             constant float2* viewportSizePtr [[buffer(spirit::kVertexInputIndexViewportSize)]])
{
    RasterizerData out;

    // Index into the array of positions to get the current vertex.
    // The positions are specified in pixel dimensions (i.e. a value of 100
    // is 100 pixels from the origin).
    float2 pixelSpacePosition = vertices[vertexID].position.xy;

    // Get the viewport size and cast to float.
//    auto viewportSize = *viewportSizePtr;
    
    // To convert from positions in pixel space to positions in clip-space,
    //  divide the pixel coordinates by half the size of the viewport.
    out.position.xy = (pixelSpacePosition / vertices[vertexID].position.z) / 2.0;
    out.position.z = 1.0;

    // Pass the input color directly to the rasterizer.
    out.color = vertices[vertexID].color;

    out.pointSize = 10.0;
    
    return out;
}

fragment float4 fragmentShader(RasterizerData in [[stage_in]])
{
    // Return the interpolated color.
    return in.color;
}

fragment float4 fragmentShaderUniform(RasterizerData_P in [[stage_in]],
                               constant float4* color [[buffer(spirit::kFragmentInputIndexColor)]]) {
    return *color;
}

