/*
 * FtAudioDsp.c
 * Hamilton Kibbe
 * Copyright 2013 Hamilton Kibbe
 */

#include "FtAudioDsp.h"
#include "FtAudioUtilities.h"
#include <string.h>

#ifdef __APPLE__
#include <Accelerate/Accelerate.h>
#endif


/* FtAudioFloatBufferToInt16 **************************************************/
FtAudioError_t
FtAudioFloatBufferToInt16(signed short* dest, const float* src, unsigned length)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    vDSP_vfix16(src,1,dest,1,length);
    
#else
    // Otherwise do it manually
    unsigned i;
    for (i = 0; i < length; ++i)
    {
        *dest++ = floatToInt16(*src++);
    }
#endif
    return FT_NOERR;
}


/* FtAudioInt16BufferToFloat **************************************************/
FtAudioError_t
FtAudioInt16BufferToFloat(float* dest, const signed short* src, unsigned length)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    vDSP_vflt16(src,1,dest,1,length);
    
#else
    // Otherwise do it manually
    unsigned i;
    for (i = 0; i < length; ++i)
    {
        *dest++ = int16ToFloat(*src++);
    }
#endif
    return FT_NOERR;
}



/* FtAudioFillBuffer **********************************************************/
FtAudioError_t 
FtAudioFillBuffer(float     *dest, unsigned  length, float     value)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    vDSP_vfill(&value, dest, 1, length);

#else
    // Otherwise do it manually
    unsigned i;
    for (i = 0; i < length; ++i)
    {
        *dest++ = value;
    }
#endif
    return FT_NOERR;
}


/* FtAudioCopyBuffer **********************************************************/
FtAudioError_t
FtAudioCopyBuffer(float* dest, const float* src, unsigned length)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    cblas_scopy(length, src, 1, dest, 1);
#else
    // Do it the boring way
    memcpy(dest, src, length * sizeof(float));
#endif
    return FT_NOERR;
}
    
/* FtAudioBufferAdd ***********************************************************/
FtAudioError_t
FtAudioBufferAdd(float      *dest, 
                 float      *in1, 
                 float      *in2, 
                 unsigned   length)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    vDSP_vadd((const float*)in1, 1, (const float*)in2, 1, dest, 1, length);
    
#else
    // Otherwise do it manually
    unsigned i;
    for (i = 0; i < length; ++i)
    {
        *dest++ = (*in1++) + (*in2++);
    }
    
#endif
    return FT_NOERR;
}




/* FtAudioVectorVectorMultiply ************************************************/
FtAudioError_t
FtAudioVectorVectorMultiply(float       *dest, 
                            float       *in1, 
                            float       *in2, 
                            unsigned    length)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    vDSP_vmul((const float*)in1, 1, (const float*)in2, 1, dest, 1, length);
    
#else
    // Otherwise do it manually
    unsigned i;
    for (i = 0; i < length; ++i)
    {
        *dest++ = (*in1++) * (*in2++);
    }
    
#endif
    return FT_NOERR;
}




/* FtAudioVectorScalarMultiply ************************************************/
FtAudioError_t
FtAudioVectorScalarMultiply(float       *dest, 
                            float       *in1, 
                            float       scalar, 
                            unsigned    length)
{
#ifdef __APPLE__
    // Use the Accelerate framework if we have it
    vDSP_vsmul((const float*)in1, 1, (const float*)&scalar,dest, 1, length);
    
#else
    // Otherwise do it manually
    unsigned i;
    for (i = 0; i < length; ++i)
    {
        *dest++ = (*in1++) * scalar;
    }
    
#endif
    return FT_NOERR;
}



/* FtAudioConvolve ************************************************************/
FtAudioError_t
FtAudioConvolve(float       *in1,
                unsigned    in1_length,
                float       *in2, 
                unsigned    in2_length, 
                float       *dest)
{
    
     unsigned resultLength = in1_length + (in2_length - 1);
    
#ifdef __APPLE__
    //Use Native vectorized convolution function if available
    float    *in2_end = in2 + (in2_length - 1);
    unsigned signalLength = (in2_length + resultLength);
    
    // So there's some hella weird requirement that the signal input to 
    //vDSP_conv has to be larger than (result_length + filter_length - 1),
    // (the output vector length) and it has to be zero-padded. What. The. Fuck!
    float padded[signalLength];
    
    //float zero = 0.0;
    FtAudioFillBuffer(padded, signalLength, 0.0);
    
    // Pad the input signal with (filter_length - 1) zeros.
    cblas_scopy(in1_length, in1, 1, (padded + (in2_length - 1)), 1);
    vDSP_conv(padded, 1, in2_end, -1, dest, 1, resultLength, in2_length);
    
#else
    // Use (boring, slow) canonical implementation
    unsigned i;
    for (i = 0; i <resultLength; ++i)
    {
        unsigned kmin, kmax, k;
        dest[i] = 0;
            
        kmin = (i >= (in2_length - 1)) ? i - (in2_length - 1) : 0;
        kmax = (i < in1_length - 1) ? i : in1_length - 1;
        for (k = kmin; k <= kmax; k++)
        {
            dest[i] += in1[k] * in2[i - k];
        }
    }   
    

#endif
    return FT_NOERR;
}
