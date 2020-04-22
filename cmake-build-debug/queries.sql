--Daniel Sanchez and Emma Lilly
--CSCI 403
--Project 9

DROP TABLE IF EXISTS office_line_comparison;

CREATE TABLE office_line_comparison (
	season		int,
	episode		int,
	Michael_Lines	text,
	Dwight_Lines	text,
	Jim_Lines	text,
	Pam_Lines	text,
	Andy_Lines	text
);


INSERT INTO office_line_comparison (
SELECT season, episode,
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
		AND od1.episode=od2.episode) as Andy_Lines
FROM office_data od1
GROUP BY season, episode
ORDER BY season, episode
);
