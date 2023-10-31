__kernel void fft(__global const float * input, __global float2 * output, int n) {
	int i = get_global_id(0);

    float2 temp_output = (float2)(0.0f, 0.0f);

    for (int j = 0; j < n; j++) {
        float angle = -2.0f * M_PI * i * j / n;
        float2 twiddle = (float2)(cos(angle), sin(angle));
        float2 value = (float2)(input[j], input[j]);
        temp_output += value * twiddle;
    }

    output[i] = temp_output;

}