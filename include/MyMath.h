#ifndef _MYMATH_H_
#define _MYMATH_H_

#pragma once

/*
* �ݹ�ʵ��
*/
__int64 gcdEU_R(__int64 a, __int64 b) { //assert: 0 <= min(a, b)
    return (0 == b) ? a : gcdEU_R(b, a % b);
}

/*
* ����ʵ��
*/
__int64 gcdEU(__int64 a, __int64 b) { //assert: 0 <= min(a, b)
    while (true) {
        if (0 == a) return b;
        if (0 == b) return a;
        if (a > b) a %= b;
        else       b %= a;
    }
}

#endif