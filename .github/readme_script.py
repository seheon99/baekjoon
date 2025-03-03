import requests
from sys import argv

USERNAME = argv[1]
SOLVED_URL = f"https://solved.ac/seyu"
BADGE_URL = f"http://mazassumnida.wtf/api/generate_badge?boj={USERNAME}"
USER_API_URL = "https://solved.ac/api/v3/user/show"
TOP_100_API_URL = "https://solved.ac/api/v3/user/top_100"

TOP_TIER = 30
TIER_TITLE = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"]
TIER_COLOR = ["#ad5600", "#435f7a", "#ec9a00", "#27e2a4", "#00b4fc", "#ff0062"]
TIER_LEVEL = ["V", "IV", "III", "II", "I"]
TIER_RATING = [
    30,
    60,
    90,
    120,
    150,
    200,
    300,
    400,
    500,
    650,
    800,
    950,
    1100,
    1250,
    1400,
    1600,
    1750,
    1900,
    2000,
    2100,
    2200,
    2300,
    2400,
    2500,
    2600,
    2700,
    2800,
    2850,
    2900,
    2950,
]

get_tier_title = lambda x: f"{TIER_TITLE[(x - 1) // 5]} {TIER_LEVEL[(x - 1) % 5]}"

request = requests.get(USER_API_URL, {"handle": USERNAME})
user = request.json()

tier = user["tier"]
rating = user["rating"]
rating_by_problems_sum = user["ratingByProblemsSum"]
rating_by_class = user["ratingByClass"]
rating_by_solved_count = user["ratingBySolvedCount"]
solved_count = user["solvedCount"]

print(f"[![solved.ac Profile]({BADGE_URL})]({SOLVED_URL})")
print()
print(
    f"$\\huge{{\\rm{{\\color{{{TIER_COLOR[(tier) // 5]}}}{get_tier_title(tier + 1)}}}}}$까지 **+{TIER_RATING[tier] - rating}** 남음"
)
print()

print("## 레이팅 종합")
print()

get_rating = lambda x: round(175 * (1 - 0.995**x))
count = 0
while (
    get_rating(solved_count + count) == get_rating(solved_count)
    and rating_by_solved_count != 175
):
    count += 1

print(f"| {get_tier_title(tier)} | +{rating}")
print("| --- | --: |")
print(f"| 상위 100문제의 난이도 합 | **+{rating_by_problems_sum}** |")
print(f"| CLASS {user['class']} | **+{rating_by_class}** |")
print(
    f"| 문제수에 따른 보너스 점수 _(다음 점수까지 **{count}**문제[^1])_ | **+{rating_by_solved_count}** |"
)

print()
print("## 난이도 별 얻게 될 점수")
print()

request = requests.get(TOP_100_API_URL, {"handle": USERNAME})
top_100 = request.json()
lowest_point = top_100["items"][-1]["level"]

print("| Level | Earning Points |")
print("| :---: | -------------: |")
for n in range(min(tier + 5, TOP_TIER), tier - 4, -1):
    print(f"| {get_tier_title(n)} | +{max(n - lowest_point, 0)} |")

print()

print(
    f"[^1]: $ {rating_by_solved_count + 1} = \\lfloor 175 \\times (1 - 0.995 ^ {{{solved_count + count}}} ) \\rceil $"
)
