def solution(friends, gifts):
    gift_degrees = { other: 0 for other in friends }
    gift_matrix = { name: { other: 0 for other in friends } for name in friends }
    for log in gifts:
        gifter, giftee = log.split()
        gift_matrix[gifter][giftee] += 1
        gift_degrees[gifter] += 1
        gift_degrees[giftee] -= 1
    
    gift_predicts = { name: 0 for name in friends }
    for me in friends:
        for you in friends:
            if me == you:
                continue
            if gift_matrix[me][you] < gift_matrix[you][me]:
                gift_predicts[you] += 1
            if gift_matrix[me][you] == gift_matrix[you][me] and gift_degrees[me] < gift_degrees[you]:
                gift_predicts[you] += 1
    
    return max(gift_predicts.values())