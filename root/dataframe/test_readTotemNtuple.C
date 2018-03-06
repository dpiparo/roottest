using namespace ROOT::Experimental;

int test_readTotemNtuple() {

   TDataFrame d("TotemNtuple", "Slimmed_TotemNTuple_9883.040.ntuple.root");
   auto validate_x = [](double v){
      std::cout << v << std::endl;
   };
   d.Foreach(validate_x, {"track_rp_3.x"});

   // now jitted with alias
   auto count0 = d.Alias("t_y", "track_rp_3.y").Filter("cout << t_y << endl; return true;").Count();
   *count0;
   // now jitted
   auto count = d.Filter("cout << track_rp_3.y << endl; return true;").Count();
   *count;

   return 0;
}
