#include "Gnuplot.h"

Gnuplot::Gnuplot()
{
	// gnuplotの起動コマンド
	if ((gnuplot = _popen("gnuplot -persist", "w")) == NULL)
	{
		cout << "ファイルが見つかりません" << endl;
		exit(1);
	}
}

Gnuplot::~Gnuplot()
{
	fprintf(gnuplot, "exit\n");	// gnuplotの終了
	_pclose(gnuplot);
}

void Gnuplot::SetXRange(int lower, int higher)
{
	fprintf(gnuplot, "set xrange[%d:%d]\n", lower, higher);
}

void Gnuplot::SetYRange(int lower, int higher)
{
	fprintf(gnuplot, "set yrange[%d:%d]\n", lower, higher);
}

void Gnuplot::Plot(const char* str)
{
	fprintf(gnuplot, "plot %s\n", str);
	fflush(gnuplot);
}

void Gnuplot::PlotBegin()
{
	fprintf(gnuplot, "plot '-'\n");
}

void Gnuplot::PlotBegin(const char* str)
{
	fprintf(gnuplot, "plot %s\n", str);
}

void Gnuplot::AddPlotData(float x, float y)
{
	fprintf(gnuplot, "%f\t%f\n", x, y);
}

void Gnuplot::PlotEnd()
{
	fprintf(gnuplot, "e\n");
}

void Gnuplot::SetTitle(const char* title)
{
	fprintf(gnuplot, "set title '%s'\n", title);
}

void Gnuplot::SetXLabel(const char* label)
{
	fprintf(gnuplot, "set xlabel '%s'\n", label);
}

void Gnuplot::SetYLabel(const char* label)
{
	fprintf(gnuplot, "set ylabel '%s'\n", label);
}

void Gnuplot::SetTerm(const char* term, int number)
{
	fprintf(gnuplot, "set term %s %d\n", term, number);
}

void Gnuplot::Plot(const char* fileName, const char* str)
{
	fprintf(gnuplot, "plot \"%s\" %s\n", fileName, str);
	fflush(gnuplot);
}

void Gnuplot::AddPlot(const char* fileName, const char* str)
{
	fprintf(gnuplot, "replot \"%s\" %s\n", fileName, str);
	fflush(gnuplot);
}

void Gnuplot::SetAnimation(float dTime, float sec)
{
	deltTime = dTime;
	playTime = sec;
	int frequency = (int)1 / deltTime * playTime;

	fprintf(gnuplot, "do for[i = 1:%d] {\n", frequency);
	Pause();
}

void Gnuplot::PlotAnimation(const char* fileName, const char* str)
{
	fprintf(gnuplot, "plot \"%s\" every ::0::i %s\n", fileName, str);
	fflush(gnuplot);
}

void Gnuplot::AddAnimation(const char* fileName, const char* str)
{
	fprintf(gnuplot, "replot \"%s\" every ::0::i %s\n", fileName, str);
	fflush(gnuplot);
}

void Gnuplot::Pause()
{
	fprintf(gnuplot, "pause %f \n", deltTime);
}

void Gnuplot::Pause(float dTime)
{
	fprintf(gnuplot, "pause %f\n", dTime);
}

void Gnuplot::EndAnimation()
{
	fprintf(gnuplot, " } \n");
}

// 棒グラフの表示
void Gnuplot::PlotBar(const char* fileName, int max)
{
	SetYRange(0, max+1);
	fprintf(gnuplot, "set boxwidth 0.75 relative\n");
	fprintf(gnuplot, "set style fill solid border lc rgb \"black\"\n");
	fprintf(gnuplot, "plot \"%s\" using 0:2:xtic(1) with boxes lw 2 title \"Result\"\n", fileName);
	fflush(gnuplot);
}