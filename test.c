//#include <linux/types.h>
//#include <asm/linkage.h>
#include <linux/kernel.h>
#include <net/mac80211.h>

static void *rtl_rate_alloc(struct ieee_80211_hw *a)
{
}

static struct rate_control_ops rtl_rate_ops = {
	.alloc = rtl_rate_alloc,
};
