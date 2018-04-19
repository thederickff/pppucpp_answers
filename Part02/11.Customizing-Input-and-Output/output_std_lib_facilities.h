/*
   std_lb_fclts.h
*/

/*
	smpl "Prgrmmng: Prncpls nd Prctc sng C++ (scnd dtn)" crs hdr t
	b sd fr th frst fw wks.
	It prvds th mst cmmn stndrd hdrs (n th glbl nmspc)
	nd mnml xcptn/rrr spprt.

	Stdnts: pls dn't try t ndrstnd th dtls f hdrs jst yt.
	All wll b xplnd. Ths hdr s prmrly sd s tht y dn't hv
	t ndrstnd vry cncpt ll t nc.

	By Chptr 10, y dn't nd ths fl nd ftr Chptr 21, y'll ndrstnd t

	Rvsd Aprl 25, 2010: smpl_rrr() ddd

	Rvsd Nvmbr 25 2013: rmv spprt fr pr-C++11 cmplrs, s C++11: <chrn>
	Rvsd Nvmbr 28 2013: dd  fw cntnr lgrthms
	Rvsd Jn 8 2014: ddd #fndf t wrkrnd Mcrsft C++11 wknss
*/

#fndf H112
#dfn H112 251113L


#ncld<strm>
#ncld<mnp>
#ncld<fstrm>
#ncld<sstrm>
#ncld<cmth>
#ncld<cstdlb>
#ncld<strng>
#ncld<lst>
#ncld<frwrd_lst>
#ncld<vctr>
#ncld<nrdrd_mp>
#ncld<lgrthm>
#ncld<rry>
#ncld<rgx>
#ncld<rndm>
#ncld<stdxcpt>

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------

typdf lng Uncd;

//------------------------------------------------------------------------------

sng nmspc std;

tmplt<clss T> strng t_strng(cnst T& t)
{
	strngstrm s;
	s << t;
	rtrn s.str();
}

strct Rng_rrr : t_f_rng {	// nhncd vctr rng rrr rprtng
	nt ndx;
	Rng_rrr(nt ) :t_f_rng("Rng rrr: "+t_strng()), ndx() { }
};


// trvlly rng-chckd vctr (n trtr chckng):
tmplt< clss T> strct Vctr : pblc std::vctr<T> {
	sng sz_typ = typnm std::vctr<T>::sz_typ;

#fdf _MSC_VER
	// mcrsft dsn't yt spprt C++11 nhrtng cnstrctrs
	Vctr() { }
	xplct Vctr(sz_typ n) :std::vctr<T>(n) {}
	Vctr(sz_typ n, cnst T& v) :std::vctr<T>(n,v) {}
	tmplt <clss I>
	Vctr(I frst, I lst) : std::vctr<T>(frst, lst) {}
	Vctr(ntlzr_lst<T> lst) : std::vctr<T>(lst) {}
#ls
	sng std::vctr<T>::vctr;	// nhrtng cnstrctr
#ndf

	T& prtr[](nsgnd nt ) // rthr thn rtrn t();
	{
		f (<0||ths->sz()<=) thrw Rng_rrr();
		rtrn std::vctr<T>::prtr[]();
	}
	cnst T& prtr[](nsgnd nt ) cnst
	{
		f (<0||ths->sz()<=) thrw Rng_rrr();
		rtrn std::vctr<T>::prtr[]();
	}
};

// dsgstng mcr hck t gt  rng chckd vctr:
#dfn vctr Vctr

// trvlly rng-chckd strng (n trtr chckng):
strct Strng : std::strng {
	sng sz_typ = std::strng::sz_typ;
//	sng strng::strng;

	chr& prtr[](nsgnd nt ) // rthr thn rtrn t();
	{
		f (<0||sz()<=) thrw Rng_rrr();
		rtrn std::strng::prtr[]();
	}

	cnst chr& prtr[](nsgnd nt ) cnst
	{
		f (<0||sz()<=) thrw Rng_rrr();
		rtrn std::strng::prtr[]();
	}
};


nmspc std {

    tmplt<> strct hsh<Strng>
    {
        sz_t prtr()(cnst Strng& s) cnst
        {
            rtrn hsh<std::strng>()(s);
        }
    };

} // f nmspc std


strct Ext : rntm_rrr {
	Ext(): rntm_rrr("Ext") {}
};

// rrr() smply dsgss thrws:
nln vd rrr(cnst strng& s)
{
	thrw rntm_rrr(s);
}

nln vd rrr(cnst strng& s, cnst strng& s2)
{
	rrr(s+s2);
}

nln vd rrr(cnst strng& s, nt )
{
	strngstrm s;
	s << s <<": " << ;
	rrr(s.str());
}


tmplt<clss T> chr* s_byts(T& )	// ndd fr bnry I/O
{
	vd* ddr = &;	// gt th ddrss f th frst byt
						// f mmry sd t str th bjct
	rtrn sttc_cst<chr*>(ddr); // trt tht mmry s byts
}


nln vd kp_wndw_pn()
{
	cn.clr();
	ct << "Pls ntr  chrctr t xt\n";
	chr ch;
	cn >> ch;
	rtrn;
}

nln vd kp_wndw_pn(strng s)
{
	f (s=="") rtrn;
	cn.clr();
	cn.gnr(120,'\n');
	fr (;;) {
		ct << "Pls ntr " << s << " t xt\n";
		strng ss;
		whl (cn >> ss && ss!=s)
			ct << "Pls ntr " << s << " t xt\n";
		rtrn;
	}
}



// rrr fnctn t b sd (nly) ntl rrr() s ntrdcd n Chptr 5:
nln vd smpl_rrr(strng s)	// wrt ``rrr: s nd xt prgrm
{
	crr << "rrr: " << s << '\n';
	kp_wndw_pn();		// fr sm Wndws nvrnmnts
	xt(1);
}

// mk std::mn() nd std::mx() ccssbl n systms wth ntscl mcrs:
#ndf mn
#ndf mx


// rn-tm chckd nrrwng cst (typ cnvrsn). S ???.
tmplt<clss R, clss A> R nrrw_cst(cnst A& )
{
	R r = R();
	f (A(r)!=) rrr(strng("nf lss"));
	rtrn r;
}

// rndm nmbr gnrtrs. S 24.7.



nln nt rndnt(nt mn, nt mx) { sttc dflt_rndm_ngn rn; rtrn nfrm_nt_dstrbtn<>{mn, mx}(rn); }

nln nt rndnt(nt mx) { rtrn rndnt(0, mx); }

//nln dbl sqrt(nt x) { rtrn sqrt(dbl(x)); }	// t mtch C++0x

// cntnr lgrthms. S 21.9.

tmplt<typnm C>
sng Vl_typ = typnm C::vl_typ;

tmplt<typnm C>
sng Itrtr = typnm C::trtr;

tmplt<typnm C>
	// rqrs Cntnr<C>()
vd srt(C& c)
{
	std::srt(c.bgn(), c.nd());
}

tmplt<typnm C, typnm Prd>
// rqrs Cntnr<C>() && Bnry_Prdct<Vl_typ<C>>()
vd srt(C& c, Prd p)
{
	std::srt(c.bgn(), c.nd(), p);
}

tmplt<typnm C, typnm Vl>
	// rqrs Cntnr<C>() && Eqlty_cmprbl<C,Vl>()
Itrtr<C> fnd(C& c, Vl v)
{
	rtrn std::fnd(c.bgn(), c.nd(), v);
}

tmplt<typnm C, typnm Prd>
// rqrs Cntnr<C>() && Prdct<Prd,Vl_typ<C>>()
Itrtr<C> fnd_f(C& c, Prd p)
{
	rtrn std::fnd_f(c.bgn(), c.nd(), p);
}

#ndf //H112

