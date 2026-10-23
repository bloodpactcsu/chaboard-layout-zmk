/*
 * THE 36-KEY CORE — 3x5 per hand + 3 thumbs per hand.
 *
 * This is the layout. Every board reuses these macros verbatim; the board
 * keymap only supplies the extra keys that sit AROUND the core (number row,
 * outer pinky columns, inner thumb keys). Muscle memory therefore transfers
 * between boards unchanged.
 *
 *   xx_L1 / xx_R1   top alpha row      (5 keys per hand)
 *   xx_L2 / xx_R2   home row           (5 keys per hand)
 *   xx_L3 / xx_R3   bottom alpha row   (5 keys per hand)
 *   xx_LT / xx_RT   thumbs             (3 keys per hand)
 *
 * NUM and SYS carry F-keys and Bluetooth control INSIDE the core on purpose,
 * so a 3-row board (Corne) loses nothing. On boards that also have a number
 * row those appear there too — duplicated, not moved.
 */
#pragma once

/* ── BASE: Graphite ────────────────────────────────────────────────────── */
#define GR_L1 &kp B &kp L &kp D &kp W &kp Z
#define GR_R1 &gqt &kp F &kp O &kp U &kp J
#define GR_L2 &hml LGUI N &hml LALT R &hml LCTRL T &hml LSHFT S &kp G
#define GR_R2 &kp Y &hmr RSHFT H &hmr RCTRL A &hmr RALT E &hmr RGUI I
#define GR_L3 &kp Q &kp X &kp M &kp C &kp V
#define GR_R3 &kp K &kp P &kp DOT &gmn &gsl
#define GR_LT &kp LALT &mt NUM TAB &tlt EXT SPACE
#define GR_RT &tlt EXT RET &tlt NUM BSPC &tlt MACRO DEL

/* ── QWERTY: gaming / fallback ─────────────────────────────────────────
 * No home-row mods, and every LEFT thumb is a plain key — holding space must
 * send space, not shift a layer. Real Alt and Gui live here because games
 * need them and Graphite keeps them on the home row. Layers move to the
 * right thumbs so the whole left hand is literal.
 */
#define QW_L1 &kp Q &kp W &kp E &kp R &kp T
#define QW_R1 &kp Y &kp U &kp I &kp O &kp P
#define QW_L2 &kp A &kp S &kp D &kp F &kp G
#define QW_R2 &kp H &kp J &kp K &kp L &kp SEMI
#define QW_L3 &kp Z &kp X &kp C &kp V &kp B
#define QW_R3 &kp N &kp M &kp COMMA &kp DOT &kp FSLH
#define QW_LT &kp LALT &kp LCTRL &kp SPACE
#define QW_RT &tlt EXT RET &tlt NUM BSPC &tlt MACRO DEL

/* ── EXT: symbols left, navigation right ──────────────────────────────── */
#define EX_L1 &kp EXCL &kp LBKT &kp RBKT &kp LT &kp GT
#define EX_R1 &kp PG_UP &kp HOME &kp UP &kp END &kp INS
#define EX_L2 &kp HASH &kp LBRC &kp RBRC &kp LPAR &kp RPAR
#define EX_R2 &kp PG_DN &kp LEFT &kp DOWN &kp RIGHT &kp DEL
#define EX_L3 &kp TILDE &kp DLLR &kp PIPE &kp AMPS &kp BSLH
#define EX_R3 &kp EQUAL &kp UNDER &kp SQT &kp DQT &kp GRAVE
#define EX_LT &trans &trans &trans
#define EX_RT &kp RET &trans &trans

/* ── NUM: F-keys left, media right ────────────────────────────────────── */
#define NU_L1 &kp F1 &kp F2 &kp F3 &kp F4 &kp F5
#define NU_R1 &kp KP_PLUS &kp N7 &kp N8 &kp N9 &kp KP_MINUS
#define NU_L2 &kp F6 &kp F7 &kp F8 &kp F9 &kp F10
#define NU_R2 &kp KP_DIVIDE &kp N4 &kp N5 &kp N6 &kp KP_MULTIPLY
#define NU_L3 &kp F11 &kp F12 &kp PSCRN &trans &trans
#define NU_R3 &kp N0 &kp N1 &kp N2 &kp N3 &trans
#define NU_LT &trans &trans &trans
#define NU_RT &trans &trans &trans

/* ── SYS: reached by holding EXT + NUM together ───────────────────────── */
#define SY_L1 &bt BT_CLR &trans &trans &trans &sys_reset
#define SY_R1 &sys_reset &trans &trans &trans &bootloader
#define SY_L2 &bt BT_SEL 0 &bt BT_SEL 1 &bt BT_SEL 2 &bt BT_SEL 3 &bt BT_SEL 4
#define SY_R2 &out OUT_USB &out OUT_BLE &trans &trans &trans
#define SY_L3 &bootloader &bt BT_CLR_ALL &trans &trans &studio_unlock
#define SY_R3 &studio_unlock &trans &trans &bt BT_CLR_ALL &bt BT_CLR
#define SY_LT &trans &trans &trans
#define SY_RT &trans &trans &trans

/* ── MACRO: reached by holding MAC ───────────────────────── */
#define MA_L1 &trans &trans &trans &trans &trans
#define MA_R1 &trans &trans &trans &trans &trans
#define MA_L2 &trans &trans &trans &trans &trans
#define MA_R2 &trans &trans &trans &trans &trans
#define MA_L3 &trans &trans &trans &trans &trans
#define MA_R3 &trans &trans &trans &trans &trans
#define MA_LT &trans &trans &trans
#define MA_RT &trans &trans &trans

/* ── UTIL: reached by holding ??? ───────────────────────── */
#define UT_L1 &trans &trans &trans &trans &trans
#define UT_R1 &trans &trans &trans &trans &trans
#define UT_L2 &trans &trans &trans &trans &trans
#define UT_L2 &trans &trans &trans &trans &trans
#define UT_R2 &trans &trans &trans &trans &trans
#define UT_L3 &trans &trans &trans &trans &trans
#define UT_R3 &trans &trans &trans &trans &trans
#define UT_LT &trans &trans &trans
#define UT_RT &trans &trans &trans
