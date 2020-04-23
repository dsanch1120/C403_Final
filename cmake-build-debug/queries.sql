--Daniel Sanchez and Emma Lilly
--CSCI 403
--Project 9

DROP TABLE IF EXISTS office_line_comparison;

CREATE TABLE office_line_comparison (
	season		int,
	episode		int,
	ratings     float,
	Michael_Lines	text,
	Dwight_Lines	text,
	Jim_Lines	text,
	Pam_Lines	text,
	Andy_Lines	text,
	Oscar_Lines	text,
	Angela_Lines	text,
	Kevin_Lines	text,
	Creed_Lines	text,
	Stanley_Lines	text,
	Phylis_Lines	text,
	Meredith_Lines	text,
	Toby_Lines	text,
	Kelly_Lines	text,
	Ryan_Lines	text,
	Erin_Lines	text
);


INSERT INTO office_line_comparison (
SELECT od1.season, od1.episode, or1.rating,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Michael'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Michael_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Dwight'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Dwight_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Jim'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Jim_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Pam'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Pam_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Andy'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Andy_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Oscar'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Oscar_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Angela'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Angela_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Kevin'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Kevin_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Creed'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Creed_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Stanley'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Stanley_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Phylis'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Phylis_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Meredith'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Meredith_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Toby'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Toby_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Kelly'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Kelly_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Ryan'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Ryan_Lines,
	(SELECT COUNT(line_text)
		FROM office_data od2
		WHERE speaker='Erin'
		AND od1.season=od2.season
		AND od1.episode=od2.episode) as Erin_Lines
FROM office_data od1, office_ratings or1
WHERE od1.episode=or1.episode AND od1.season=or1.season
GROUP BY od1.season, od1.episode, or1.rating
ORDER BY od1.season, od1.episode
);
