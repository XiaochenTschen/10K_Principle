from datetime import datetime
from datetime import timedelta
# 时间字符串
time_str1 = "17:15"
time_str2 = "8:45"

# 解析时间字符串
time_format = "%H:%M"
# 得到两个datatime对象
time1 = datetime.strptime(time_str1, time_format)
time2 = datetime.strptime(time_str2, time_format)

# 计算时间差得到timedelta对象
time_diff = time1 - time2
print(time_diff)

rest_time = timedelta(minutes=30)
time_diff -= rest_time
print(time_diff)

# 格式化输出
time_diff_str = "{}h{}min".format(time_diff.seconds // 3600, (time_diff.seconds // 60) % 60)
print(time_diff_str)

from datetime import timedelta

# 创建一个 timedelta 对象，表示3天4小时5分钟6秒
td = timedelta(days=3, hours=4, minutes=5, seconds=6)

print("days:", td.days)
print("seconds:", td.seconds)
print("microseconds:", td.microseconds)
print("total seconds:", td.total_seconds())
